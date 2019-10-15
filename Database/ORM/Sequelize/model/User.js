const { Model } = require('sequelize');
const sequelize = require('./db/Sequelize');
const { UserTables } = require('./db/tables');

class User extends Model {}
User.init(UserTables, { sequelize, modelName: 'user' });

module.exports = User;
