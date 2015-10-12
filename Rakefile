compiler = ENV.fetch('CC', 'gcc')
compiler_location = `which #{compiler}`.strip
compiler_info = `#{compiler} --version 2>&1`.strip

SYSTEM_TEST_HOST = ENV.fetch('SYSTEM_TEST_HOST', "localhost")

require 'ceedling'
Ceedling.load_project(config: './config/project.yml')

def report(message='')
  $stderr.flush
  $stdout.flush
  puts message
  $stderr.flush
  $stdout.flush
end

def report_banner(message)
  report "\n#{message}\n#{'='*message.length}\n\n"
end

def execute_command(cmd, banner=nil)
  report_banner banner unless banner.nil?
  report "Executing: #{cmd}"
  sh cmd
  report
  report unless banner.nil?
end

def git(cmd)
  execute_command "git #{cmd}"
end

HERE = File.expand_path(File.dirname(__FILE__))
BUILD_ARTIFACTS = File.join(HERE, 'build', 'artifacts', 'release')
TEST_ARTIFACTS = File.join(HERE, 'build', 'artifacts', 'test')
TEST_TEMP = File.join(HERE, 'build', 'test', 'temp')
DOCS_PATH = File.join(HERE, 'docs/api')

directory DOCS_PATH
CLOBBER.include DOCS_PATH
directory TEST_TEMP
CLOBBER.include TEST_TEMP

task :report_toolchain do
  report_banner("Toolchain Configuration")
  report "" +
    "compiler:\n" +
    "  location: #{compiler_location}\n" +
    "  info:\n" +
    "    " + compiler_info.gsub(/\n/, "\n    ")
end

task :test => ['report_toolchain', 'test:delta']

namespace :tests do

  desc "Run unit tests"
  task :unit => ['report_toolchain'] do
    report_banner "Running Unit Tests"
    Rake::Task['test:path'].reenable
    Rake::Task['test:path'].invoke('test/unit')
  end

  desc "Run integration tests"
  task :integration => ['report_toolchain'] do
    report_banner "Running Integration Tests"
    Rake::Task['test:path'].reenable
    Rake::Task['test:path'].invoke('test/integration')
  end

end

task :test_all => ['report_toolchain', 'tests:unit', 'tests:integration']

task :default => ['report_toolchain', 'test:delta']

namespace :doxygen do

  VERSION = File.read('./config/VERSION').strip

  task :checkout_github_pages => ['clobber', DOCS_PATH] do
    git "clone git@github.com:seagate/kinetic-c.git -b gh-pages #{DOCS_PATH}"
  end

  desc "Generate API docs"
  task :gen => [DOCS_PATH] do
    # Update API version in doxygen config
    doxyfile = "config/Doxyfile"
    content = File.read(doxyfile)
    content.sub!(/^PROJECT_NUMBER +=.*$/, "PROJECT_NUMBER           = \"v#{VERSION}\"")
    File.open(doxyfile, 'w').puts content

    # Generate the Doxygen API docs
    report_banner "Generating Doxygen API Docs (kinetic-c v#{VERSION})"
    execute_command "doxygen #{doxyfile}"
  end

  desc "Generate and publish API docs"
  task :update_public_api => ['doxygen:checkout_github_pages', 'doxygen:gen'] do
    cd DOCS_PATH do
      git "add --all"
      git "status"
      git "commit -m 'Regenerated API docs for v#{VERSION}'"
      git "push"
      report_banner "Published updated API docs for v#{VERSION} to GitHub!"
    end
  end

end
