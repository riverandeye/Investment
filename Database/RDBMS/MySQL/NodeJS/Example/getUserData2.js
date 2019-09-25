const db = require('../modules/db2');

async function getData(){
    const data = await db.query('SELECT * FROM `Card`');
    console.log(data);
}
getData();

// async function getConnection(){
//     return new Promise(
//         (resolve, reject)=>{
//             db.getConnection(
//                 (err, connection)=>{
//                     !err ? resolve(connection) : reject(err);
//                 }
//             )
//         }
//     )
// }

// async function getData(){
//     const connection = await getConnection();

//     const [rows, fields] = await connection.promise().execute(
//         'SELECT * FROM `Card`'
//     )

//     console.log(rows);
//     connection.release();
// }

// getData();

