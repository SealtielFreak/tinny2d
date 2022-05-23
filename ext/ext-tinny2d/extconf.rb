require 'mkmf'
require_relative 'auxlib.rb'

CHECK_PACKAGE = Arguments.include? 'install-package'
LIBS = {}
MODE_COMPILE = if Arguments.include? 'static' and System.window? then :static_window else :generic end 

LIBS[:static_window] = %w[
  csfml-graphics-s
  csfml-window-s
  csfml-system-s
  csfml-audio-s

  opengl32
  winmm
  gdi32
  FLAC
  freetype
  ogg
  openal32
  vorbis
  vorbisenc
  vorbisfile
  ws2_32
]

LIBS[:generic] = %w[
  csfml-graphics
  csfml-window
  csfml-system
  csfml-audio
]

if CHECK_PACKAGE
  puts 'Installing dependencies...'

  if System.windows?
    run_script 'msys2.sh'
  else
    run_script 'linux.sh'
  end
end

case MODE_COMPILE
when :static_window
  %w[
    -DCSFML_STATIC
  ].each { |f| append_cppflags f }

  %w[
    -static
  ].each { |f| append_cppflags f }
when :generic
  # something
end

LIBS[MODE_COMPILE].each { |l| have_library(l) }

create_makefile 'ext'
