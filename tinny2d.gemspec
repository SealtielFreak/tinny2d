require_relative 'lib/tinny2d/version'

Gem::Specification.new do |s|
    s.name        = 'tinny2d'
    s.version     = Tinny::VERSION
    s.summary     = 'Experimental game framework for Ruby'
    s.description = 'Tinny2D is a game framework like Löve2D and Ruby2D, power by CSFML'
    s.homepage    = 'https://github.com/sealtielfreak/tinny2d/'
    
    s.authors     = ['Sealtiel Valderrama']
    s.email       = 'SealtielFreak@yandex.com'
    s.license     = 'LGPL-2.1'

    #s.required_ruby_version = '>= 2.5.0'
    #s.add_development_dependency 'rake', '~> 11.2', '>= 11.2.2'

    s.files       = Dir.glob('ext/ext-tinny2d/**/*.{h,c,rb,sh}') +
                    Dir.glob('lib/**/*.{rb}') +
                    Dir.glob('test/**/*.{rb,png,otf}') +
                    Dir.glob('bin/**/*.{rb}') +
                    Dir.glob('assets/**/*.{otf}')

    s.extensions  = ['ext/ext-tinny2d/extconf.rb']
end
