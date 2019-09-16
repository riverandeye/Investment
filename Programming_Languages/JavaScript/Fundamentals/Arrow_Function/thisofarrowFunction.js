const obj = {
    init() {
        const button = document.getElementById('shit');
        button.addEventListener("click", () => {
            this.log();
        });
    },
    fn() {
        this.log();
    },
    log() {
        console.log("test");
    }
};

obj.init();