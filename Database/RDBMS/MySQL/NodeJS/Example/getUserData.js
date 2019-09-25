const db = require('../modules/db');

async function getdata(){

    const [rows, fields] = await db.promise().execute(
        'SELECT * FROM `Card`'
    );

    return rows;
}

// (async()=>{
//     const data = await getdata();
//     console.log(data);
//     console.log('poop');
// })();