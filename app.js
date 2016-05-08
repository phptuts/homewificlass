var express = require('express');
var app = express();

app.use('/assets', express.static('assets'));
var isLightOn = false;

// respond with "hello world" when a GET request is made to the homepage
app.get('/', function(req, res) {
  res.sendFile(__dirname  + '/index.html');
});

app.get('/lightswitch/:isON', function(req, res) {
    console.log(req.params.isON);
    isLightOn =  req.params.isON === "true";
    res.send({"success" : true});
});

app.get('/lightstate', function(req, res) {
    res.send(isLightOn);    
});

app.listen(process.env.PORT, function () {
  console.log('Example app listening on port ' + process.env.PORT + '!');
});