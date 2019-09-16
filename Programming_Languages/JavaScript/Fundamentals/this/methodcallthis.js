const obj1 = {
    name : "KKH",
    sayName : function(){
        console.log(this.name);
    }
}

const obj2 = {
    name :"PJS",
}

obj2.sayName = obj1.sayName;

obj1.sayName();
obj2.sayName();