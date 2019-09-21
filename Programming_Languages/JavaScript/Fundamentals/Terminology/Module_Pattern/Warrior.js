const Warrior = (function(){

    // 비공개 멤버변수
    let health = 100;
    let age = 25;
    const updateAge = () =>{
        age++;
    }

    return {
        getHealth(){
            return health;
        },

        getAge(){
            return age;
        },

        addAge(){
            updateAge();
        }
    }
})();

console.log(Warrior.age); // undefined
console.log(Warrior.getAge()); // 25
Warrior.addAge(); 
console.log(Warrior.getAge()); // 26
