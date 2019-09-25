const db = require('../modules/db2');

async function getData(){
    const data = await db.promise().query('SELECT * FROM `Card`');
    console.log(data);
}
getData();