const sample = function(){
    console.log(this)
}
sample()

const sample2 = function(){
    const sample3 = function(){
        console.log(this);
    }
    sample3();
}
sample2();

const obj = {
    sam : function(){
        const a = function(){
            console.log(this);
        }
        a();
    }
}

obj.sam();

const obj2 = {
    sam : function(){
        setTimeout(function(){
            console.log(this);
        }, 1000)
    }
}
obj2.sam();