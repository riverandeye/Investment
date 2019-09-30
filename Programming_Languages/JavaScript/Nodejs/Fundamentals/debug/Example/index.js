const debug = require('debug')('hello');
const debug2 = require('debug')('dello');

function smth(){
    debug('hello %O 안녕', {
        h:'e',
        he:[1,2,3,4,5],
    });

    debug2("hiiiiahhhh");
}

smth();