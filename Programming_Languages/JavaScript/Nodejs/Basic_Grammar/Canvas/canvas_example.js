// Initialized thanks to https://stackoverflow.com/questions/35137936/can-i-let-node-js-generate-a-canvas-without-an-html-page

// basic Setting
var fs = require('fs');
var out = fs.createWriteStream(__dirname + '/Image/result.png');  
var Canvas = require('canvas');
var canvas = Canvas.createCanvas(600, 400); // 가로 600 x 세로 400 캔버스를 생성한다.
var stream = canvas.pngStream();

const color_white = `rgb(255,255,255)`;
const color_green = `rgb(0,255,0)`;
const color_black = `rgb(0,0,0)`;
const color_gray = `#808080`;
const color_darkblue = `#000080`;

// fill a green background
var bgr = canvas.getContext('2d');
bgr.fillStyle = color_green;
bgr.fillRect(0,0,canvas.width, canvas.height);

function drawRectangle(canvas, x, y, w, h, color = '#FFFFFF'){
    const ctx = canvas.getContext('2d');
    ctx.save();
    ctx.fillStyle = color;
    ctx.fillRect(x,y,w,h);
    ctx.restore();
}


// make a head (center of person)
var head = canvas.getContext('2d');
head.x = 150; head.y = 100; head.radius = 70;
head.beginPath();
head.arc(head.x,head.y,head.radius,0,2 * Math.PI);
head.strokeStyle = head.fillStyle = color_white;
head.stroke();
head.fill();

// make a small eye
var eye = canvas.getContext('2d');
eye.beginPath();
eye.arc(head.x + 37 * (head.radius / 75), head.y - 40 * (head.radius / 75) ,8,0,2 * Math.PI);
eye.strokeStyle = eye.fillStyle = color_black;
eye.stroke();
eye.fill();
// make a mouth
var mouth = canvas.getContext('2d');
mouth.beginPath();
mouth.moveTo(head.x, head.y);
mouth.arc(head.x,head.y,head.radius, -0.1 * Math.PI, 0.2 * Math.PI);
mouth.strokeStyle = mouth.fillStyle = color_darkblue;
mouth.stroke();
mouth.fill();
console.log(mouth.canvas);
console.log(mouth.canvas === eye.canvas);
// make a body
var body = canvas.getContext('2d');
var grd = body.createLinearGradient(0,head.y + head.radius, 0, head.y + head.radius * 3);
grd.addColorStop(0, "yellow");
grd.addColorStop(1, "red");
body.fillStyle = grd;
body.fillRect(head.x - head.radius, head.y + head.radius, 2 * head.radius, 2 * head.radius);

// make a left leg
var leftleg = canvas.getContext('2d');
leftleg.save();
leftleg.beginPath();
leftleg.moveTo(head.x - 20, head.y + head.radius * 3);
leftleg.lineTo(head.x - head.radius + 10, canvas.height);
leftleg.strokeStyle = color_black;
leftleg.lineWidth = 5;
leftleg.stroke();
leftleg.restore();

// make a right leg
var rightleg = canvas.getContext('2d');
rightleg.save();
rightleg.beginPath();
rightleg.setLineDash([9,9]);
rightleg.moveTo(head.x + 20, head.y + head.radius * 3);
rightleg.lineTo(head.x + head.radius - 10, canvas.height);
rightleg.strokeStyle = color_black;
rightleg.lineWidth = 5;
rightleg.stroke();
rightleg.setLineDash([]);
rightleg.restore();

// put a text
var Text = canvas.getContext("2d");
Text.save();
Text.font = "bold 20px Arial";
Text.textAlign = "center";
Text.fillStyle = "red";
Text.translate(head.x + head.radius * 2 + 15 , head.y + 30);
Text.rotate(30 / 180 * Math.PI);
Text.fillText("I am Mona Lisa", 0,0);
Text.restore();

// put an Arrow
var Arrow = canvas.getContext("2d");
Arrow.save();
Arrow.beginPath();
Arrow.a = 40; Arrow.b = 90; Arrow.c = 30; Arrow.d = 50;
Arrow.startx = 0;//-(Arrow.b + Arrow.d) / 2;
Arrow.starty = 0;//-(Arrow.a) / 2 - Arrow.c;
Arrow.translate(420,120);
Arrow.rotate(Math.PI * (-30 / 180));
Arrow.moveTo(Arrow.startx, Arrow.starty);
Arrow.lineTo(Arrow.startx + Arrow.b, Arrow.starty);
Arrow.lineTo(Arrow.startx + Arrow.b, Arrow.starty - Arrow.c);
Arrow.lineTo(Arrow.startx + Arrow.b + Arrow.d, Arrow.starty + Arrow.a / 2);
Arrow.lineTo(Arrow.startx + Arrow.b, Arrow.starty + Arrow.a + Arrow.c);
Arrow.lineTo(Arrow.startx + Arrow.b, Arrow.starty + Arrow.a);
Arrow.lineTo(Arrow.startx, Arrow.starty + Arrow.a);
Arrow.lineTo(Arrow.startx, Arrow.starty + Arrow.a);
Arrow.strokeStyle = Arrow.fillStyle = color_gray;
Arrow.fill();
Arrow.restore();

// add Image from URL
var canvas_image = canvas.getContext("2d");
const Mona_Lisa = "Mona_Lisa.jpg";
const data = Canvas.loadImage(Mona_Lisa).then((img)=>{
    canvas_image.drawImage(img,350,head.y + head.radius, head.radius * 2 * img.width / img.height , head.radius * 2);
    // save to PNG
    stream.on('data', function(chunk){out.write(chunk); });
    stream.on('end', function(){console.log('saved png'); }); 
}).catch((e)=>{if(e) console.log(e)});