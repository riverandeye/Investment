const { Model } = require('sequelize');
const sequelize = require('./db/Sequelize');
const { ReservationTables } = require('./db/tables');

class Reservation extends Model {}
Reservation.init(ReservationTables, { sequelize, modelName: 'reservation' });

module.exports = Reservation;
