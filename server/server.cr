require "http/server"

server = HTTP::Server.new do |context|
  
  json_data = File.read("data.json")

  callback = context.request.query_params["callback"]
  context.response.content_type = "application/json"
  context.response.print "#{callback}(#{json_data});"
end

address = server.bind_tcp 5000
puts "Listening on http://#{address}"
server.listen