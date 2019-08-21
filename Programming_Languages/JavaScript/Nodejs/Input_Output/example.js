var readline = require("readline");
var r = readline.createInterface({
    input : process.stdin,
    output : process.stdout
});

r.question("What do you wanna eat?", function(answer){
    console.log(`Yeah I really want to eat ${answer}`);
    r.close();
})

console.log("Shit happenes")

// Shit happenes 가 먼저 출력된다 : r.question은 실행할 때 wait 하지 않는다.