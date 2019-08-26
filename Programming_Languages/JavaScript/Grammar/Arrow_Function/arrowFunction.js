class Animal {
    constructor(name, age){
        this.name = name;
        this.age = age;
    }
}

class Person extends Animal{
    constructor(name, age){
        super(name, age);
    }

    talk(){
        return ()=>{
            console.log(this.name);
        }
    }

    listen(callback){
        callback();
    }
}

class Dog extends Animal {
    constructor(name, age){
        super(name, age);
    }

    talk(){
        return function(){
            console.log(`Bark! Bark! Bark! ${this.name}! Bark!`);
        }.bind(this);
    }

    listen(callback){
        callback();
    }
}

const KwanHun = new Person("KwanHun", 25);
const Lilly = new Dog("Lilly", 3);

// KwanHun.listen(Lilly.talk()); // this doesn't work
Lilly.listen(KwanHun.talk()); // this works