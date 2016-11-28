#### Script for EdX course UT6.02X
## Author: Ramesh Yerraballi
## Date: Spring 2015
## License: Freeware
## The code here is based on three sources:
##  1. The basic guestbook appengine application from Google
##  2. pymaps.py script from: https://code.google.com/p/pymaps/
##  3. ipinfo.io's ip locator is more accurate than geobytes http://ipinfo.io/
##  4. geobytes.com's ip locator at http://www.geobytes.com/iplocator/
##     and their json api 
## Need the next line to deal with strings that the geobytes server returns that
## have unicode characters -- Did not Work though
#-*- coding: UTF-8 -*-
import cgi
import time
import logging
import urllib2
import unicodedata
import webapp2
import random
import json
from google.appengine.ext import ndb

DEFAULT_MOOCBOOK_NAME = 'moocbook'

# We set a parent key on the 'Greetings' to ensure that they are all
# in the same entity group. Queries across the single entity group
# will be consistent.  However, the write rate should be limited to
# ~1/second.

def moocbook_key(moocbook_name=DEFAULT_MOOCBOOK_NAME):
    """Constructs a Datastore key for a Moocbook entity.

    We use moocbook_name as the key.
    """
    return ndb.Key('moocbook', moocbook_name)


# [START greeting]
class Greeting(ndb.Model):
    """A main model for representing an individual Guestbook entry."""
    author = ndb.StringProperty(indexed=False)
    greet = ndb.StringProperty(indexed=False)
    date = ndb.DateTimeProperty(auto_now_add=True)
    city = ndb.StringProperty(indexed=False)
    edxcode = ndb.StringProperty(indexed=False)
    score = ndb.StringProperty(indexed=False)
    edxpost = ndb.StringProperty(indexed=False)
    ipaddr = ndb.StringProperty(indexed=False)
    latitude = ndb.StringProperty(indexed=False)
    longitude = ndb.StringProperty(indexed=False)
# [END greeting]
MAIN_PAGE_HTML = """\
<html>
  <body>
    <form action="/sign" method="post">
	  <div><input type="text" name="uid" cols="4">
	  <div><input type="text" name="greet" cols="30">
    </form>
  </body>
</html>
"""


class MainPage(webapp2.RequestHandler):
    def get(self):
        self.response.write('</body></html>')
        self.response.write('<h2>Embedded Systems - University of Texas at Austin</h2>')
        self.response.write('<hr>')
        # [START query]
        greetings_query = Greeting.query(
            ancestor=moocbook_key('moocbook')).order(-Greeting.date)
        greetings = greetings_query.fetch()
        # [END query]
        
        for greeting in greetings:
            if int(greeting.score) == 100:
                self.response.write('<b>%s@%s</b>: <i>%s</i> (accessed from %s)' %
                                        (greeting.author, greeting.city, greeting.greet, greeting.ipaddr))
            self.response.write('<hr>')

class Auto(webapp2.RequestHandler):
    def get(self):
        #uncomment these three lines for debugging; So we can access it through a browser
#        if self.request.environ.get('HTTP_USER_AGENT') != 'Keil':
#           self.response.write('<html><body> <pre> Invalid Access</pre> </body></html>')
#           return
        greeting = Greeting(parent=moocbook_key('moocbook'))
        greeting.ipaddr = self.request.environ.get('REMOTE_ADDR')     
        geo_url = "http://ipinfo.io/%s/loc" % greeting.ipaddr
        # There should be some error checking here if the lookup fails
        json_stream = urllib2.urlopen(geo_url)
        retstr = json_stream.read()
        gps = retstr.split(",")
        greeting.latitude = gps[0]
        greeting.longitude = gps[1]
        greeting.author = cgi.escape(self.request.get('id'))
        greeting.city = cgi.escape(self.request.get('city'))
        edxcode = int(self.request.get('edxcode'))
        score = random.randrange(92,99)
        if (edxcode < 1000) or (edxcode > 9999):
            MagicCode= "66000000"
            score=0
        else:
            MagicCode= "66"+ str(score) +str(edxcode)
            score=100    
        # The actual code to generate the magic code is removed
        # for public dissemination of this software
        EncryptedMagicCode = ['A','B','C','@','1','2','3','4','!','\0']
        edxpost = ''.join(EncryptedMagicCode)
        greeting.greet = cgi.escape(self.request.get('greet'))
        greeting.edxcode = str(edxcode)
        greeting.edxpost = edxpost
        greeting.score = str(score)
        greeting.put()
        logging.info('Inserting record : %s', edxcode)
        self.response.write('<html><body>')
        self.response.write('<pre>{"%s":"%s", "%s":"%s", "%s":%s, "%s":%d, "%s":%s}</pre>' %
                                  ("id", greeting.author, "greet", greeting.greet, "edxcode", edxcode, "score",score,"edxpost", edxpost))
        self.response.write('</body></html>')
class ShowMap(webapp2.RequestHandler):
    def get(self):
        g = PyMap()                         # creates an icon & map by default
        icon2 = Icon('icon2')               # create an additional icon
        icon2.image = "http://labs.google.com/ridefinder/images/mm_20_blue.png" # for testing only!
        icon2.shadow = "http://labs.google.com/ridefinder/images/mm_20_shadow.png" # do not hotlink from your web page!
        g.addicon(icon2)
        g.maps[0].zoom = 2
        # [START query]
        greetings_query = Greeting.query(
            ancestor=moocbook_key('moocbook')).order(-Greeting.date)
        greetings = greetings_query.fetch()
        # [END query]
        
        for greeting in greetings:
            if greeting.latitude is not None:
                r = [greeting.latitude,greeting.longitude,greeting.author,'icon2']                # icon2.id, specify the icon but no text
                g.maps[0].setpoint(r)    
        self.response.write(g.showhtml());
application = webapp2.WSGIApplication([
    ('/', MainPage),
	('/query', Auto),
    ('/map',ShowMap)
], debug=True)

############ cut-paste from pymaps.py with minimal modifications
"""
*    Pymaps 0.9 
*    Copyright (C) 2007  Ashley Camba <stuff4ash@gmail.com> http://xthought.org
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software
*    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

Changes by Bill (not a javascript programmer@) Luitje 29 July 2009
* fixed default parameter use for lists
* fixed icon javascript generation. works!
* updated example code

Some getting started info here:
http://lycos.dropcode.net/gregarius/Lonely_Code/2008/12/04/Google_Maps_and_Django

@ and not much of a python programmer either.
"""
class Icon:
    '''Get/make marker icons at http://mapki.com/index.php?title=Icon_Image_Sets'''
    def __init__(self,id='icon'):
        self.id = id
        self.image = ""     #uses default Google Maps icon
        self.shadow = ""
##        self.image = "http://labs.google.com/ridefinder/images/mm_20_blue.png"
##        self.shadow = "http://labs.google.com/ridefinder/images/mm_20_shadow.png"
        self.iconSize = (12, 20)    # these settings match above icons
        self.shadowSize = (22, 20)
        self.iconAnchor = (6, 20)
        self.infoWindowAnchor = (5, 1)

class Map:
    def __init__(self,id="map",pointlist=None):
        self.id       = id    # div id        
        self.width    = "500px"  # map div width
        self.height   = "300px"  # map div height
        self.center   = (0,0)     # center map latitude coordinate
        self.zoom        = "1"   # zoom level
        self.navcontrols  =   True   # show google map navigation controls
        self.mapcontrols  =   True   # show toogle map type (sat/map/hybrid) controls
        if pointlist == None:
            self.points = []   # empty point list
        else:
            self.points = pointlist   # supplied point list
    
    def __str__(self):
        return self.id
        
    
    def setpoint(self, point):
        """ Add a point (lat,long,html,icon) """
        self.points.append(point)

class PyMap:
    """
    Python wrapper class for Google Maps API.
    """
    
    def __str__(self):
        return "Pymap"
    
    def __init__(self, key=None, maplist=None, iconlist=None):
        """ Default values """
        self.key      = "" # Google no longer requires a key so I just set it to null - RYs
        if maplist == None:
            self.maps = [Map()]
        else:
            self.maps = maplist
        if iconlist == None:
            self.icons = [Icon()]
        else:
            self.icons = iconlist
    
    def addicon(self,icon):
        self.icons.append(icon)
        
    def _navcontroljs(self,map):
        """ Returns the javascript for google maps control"""    
        if map.navcontrols:
            return  "           %s.gmap.addControl(new GSmallMapControl());\n" % (map.id)
        else:
            return ""    
    
    
    def _mapcontroljs(self,map):
        """ Returns the javascript for google maps control"""    
        if map.mapcontrols:
            return  "           %s.gmap.addControl(new GMapTypeControl());\n" % (map.id)
        else:
            return ""     
    
    
    def _showdivhtml(self,map):
        """ Returns html for dislaying map """
        html = """\n<div id=\"%s\">\n</div>\n""" % (map.id)
        return html
    
    def _point_hack(self, points):
        count = 1
        
        for item in points:
            open = str(item).replace("(", "[")
            open = open.replace(")", "]")
        
        return open
    
    
    def _mapjs(self,map):
        js = "%s_points = %s;\n" % (map.id,map.points)
        
        js = js.replace("(", "[")
        js = js.replace(")", "]")
        js = js.replace("u'", "'")
        js = js.replace("''","")    #python forces you to enter something in a list, so we remove it here
##        js = js.replace("'icon'", "icon")
        for icon  in self.icons:
            js = js.replace("'"+icon.id+"'",icon.id)
        js +=   """             var %s = new Map('%s',%s_points,%s,%s,%s);
        \n\n%s\n%s""" % (map.id,map.id,map.id,map.center[0],map.center[1],map.zoom, self._mapcontroljs(map), self._navcontroljs(map))
        return js
    
    
    
    def _iconjs(self,icon):
        js = """ 
                var %s = new GIcon(); 
                %s.image = "%s";
                %s.shadow = "%s";
                %s.iconSize = new GSize(%s, %s);
                %s.shadowSize = new GSize(%s, %s);
                %s.iconAnchor = new GPoint(%s, %s);
                %s.infoWindowAnchor = new GPoint(%s, %s);
        """ % (icon.id, icon.id, icon.image, icon.id, icon.shadow, icon.id, icon.iconSize[0],icon.iconSize[1],icon.id, icon.shadowSize[0], icon.shadowSize[1], icon.id, icon.iconAnchor[0],icon.iconAnchor[1], icon.id, icon.infoWindowAnchor[0], icon.infoWindowAnchor[1])
        return js
     
    def _buildicons(self):
        js = ""
        if (len(self.icons) > 0):
            for i in self.icons:
               js = js + self._iconjs(i)    
        return js
    
    def _buildmaps(self):
        js = ""
        for i in self.maps:
            js = js + self._mapjs(i)+'\n'
        return js

    def pymapjs(self):
        """ Returns complete javacript for rendering map """
        
        self.js = """\n<script src=\"http://maps.google.com/maps?file=api&amp;v=2&amp;key=%s\" type="text/javascript"></script>
        <script type="text/javascript">
        //<![CDATA[
        function load() {
            if (GBrowserIsCompatible()) {
                
            
            function Point(lat,long,html,icon) {
                  this.gpoint = new GMarker(new GLatLng(lat,long),icon);
                  this.html = html;
                  
               }               
               
               
               function Map(id,points,lat,long,zoom) {
                  this.id = id;
                  this.points = points;
                  this.gmap = new GMap2(document.getElementById(this.id));
                  this.gmap.setCenter(new GLatLng(lat, long), zoom);
                  this.markerlist = markerlist;
                  this.addmarker = addmarker;
                  this.array2points = array2points;
                   
                  function markerlist(array) {
                     for (var i in array) {
                        this.addmarker(array[i]);
                     }
                  }
                  
                  function array2points(map_points) {            
                      for (var i in map_points) {  
                        points[i] = new Point(map_points[i][0],map_points[i][1],map_points[i][2],map_points[i][3]);         }
                      return points;   
                    }                  
                  
                  function addmarker(point) {
                     if (point.html) {
                       GEvent.addListener(point.gpoint, "click", function() { // change click to mouseover or other mouse action
                           point.gpoint.openInfoWindowHtml(point.html);
                        
                       });
                       
                     }
                     this.gmap.addOverlay(point.gpoint);  
                  }
                  this.points = array2points(this.points);
                  this.markerlist(this.points);
            }  
                    %s
                    %s
            }
        }
        //]]>
        </script>
        
        
        """ % (self.key, self._buildicons(),self._buildmaps())
        return self.js 
    
    
        
    def showhtml(self):
        """returns a complete html page with a map"""
        
        self.html = """
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8"/>
    <title>Embedded Systems MOOC - UT 6.20X</title>
    %s
  </head>
  
  <body onload="load()" onunload="GUnload()">
    <div id="map" style="width: 1000px; height: 600px"></div>
  </body>
</html>
""" % (self.pymapjs())
        return self.html

####################cut-paste from pymaps.py to heree