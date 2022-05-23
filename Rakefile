require 'rake'
require_relative 'lib/tinny2d/version'

task default: 'all'

task :uninstall do
  system "gem uninstall tinny2d"
end

task :build do
  system "gem build tinny2d.gemspec"
end

task :install do
  system "gem install tinny2d-#{Tinny::VERSION}.gem"
end

task :test do
  system 'ruby test/hello-world.rb'
end

task :all do
  Rake::Task['uninstall'].invoke
  Rake::Task['build'].invoke
  Rake::Task['install'].invoke
end