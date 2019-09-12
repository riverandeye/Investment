const obj = {
    fn: function () {
        console.log(this);
    },
    log() {
        console.log("test");
    }
};

const button = document.getElementById('shit');
button.addEventListener("click", obj.fn);