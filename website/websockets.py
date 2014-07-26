import datetime
import tornado
from tornado import websocket
from tornado import httpserver
import serial

class WSHandler(websocket.WebSocketHandler):
    def open(self):
        print 'new connection'
        self.write_message("Goodbye World")
        tornado.ioloop.IOLoop.instance().add_timeout(datetime.timedelta(seconds=5), self.test)
      
    def on_message(self, message):
        print 'message received %s' % message
 
    def on_close(self):
      print 'connection closed'

    def check_origin(self, origin):
      return True
    
    def test(self):
        line = ser.readline()
        if line:
            self.write_message(line)
        tornado.ioloop.IOLoop.instance().add_timeout(datetime.timedelta(seconds=5), self.test)

      
application = tornado.web.Application([
    (r'/ws', WSHandler),
])
 
 
if __name__ == "__main__":
    ser = serial.Serial('COM3', 9600, timeout=0)
    http_server = httpserver.HTTPServer(application)
    http_server.listen(8883)
    tornado.ioloop.IOLoop.instance().start()
 
