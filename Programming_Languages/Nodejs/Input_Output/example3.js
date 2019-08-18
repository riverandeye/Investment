var readline = require("readline");
var r = readline.createInterface({
    input : process.stdin,
    output : process.stdout
});

async function askonce(r){
    return new Promise( (resolve, reject)=>{
        setTimeout(
            resolve(()=>{r.question("What do you wanna eat?", async function(answer){
                console.log(`Yeah I really want to eat ${answer}`);
                r.close();
                }
            )})
        , 12000)}
    )
}

async function main(r){
    await askonce(r).then((func)=>{func();}).catch(()=>{console.log("it is a dead end")})
}

main(r);