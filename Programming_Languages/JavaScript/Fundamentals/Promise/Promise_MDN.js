function afterresolve(){
    console.log("Yo this start after 1 second")
}

function afterreject(){
    console.log("Yo this is reject result dude")
}

var Prom1 = new Promise(function(resolve, reject){
    setTimeout(function(){
        resolve(afterresolve);
    }, 1000);
});

Prom1.then((inp)=>{inp()})
console.log(Prom1);

var Prom2 = new Promise(function(resolve,reject){
    setTimeout(function(){
        reject(afterreject)
    }, 2000);
});

const data = Prom2.then(()=>{}, (e)=>{e();console.log("this is from inside")}).catch((e)=>{e(); console.log("this is from outside")}).then(()=>{console.log("return of .then() is Promise with no delay")})