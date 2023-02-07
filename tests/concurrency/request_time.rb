require 'uri'
require 'net/http'

uri = URI('http://localhost:8000/test')

startt = Process.clock_gettime(Process::CLOCK_MONOTONIC)
res = Net::HTTP.get_response(uri)
elapsed = Process.clock_gettime(Process::CLOCK_MONOTONIC) - startt
puts "Elapsed: #{elapsed}"