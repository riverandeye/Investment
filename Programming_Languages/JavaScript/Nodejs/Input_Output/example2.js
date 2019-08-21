var readline = require("readline");
var r = readline.createInterface({
    input : process.stdin,
    output : process.stdout
});

async function askonce(r){
    await r.question("What do you wanna eat?", async function(answer){
        console.log(`Yeah I really want to eat ${answer}`);
        await r.close();
    })
}

async function main(r){
    await askonce(r)
    console.log("it is a dead end")
}

async function main2(){
    await main(r);
    console.log("Shit happenes")
}

main2();

// 이것도 안됨. 