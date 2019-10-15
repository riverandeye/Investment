const { Model } = require('sequelize');
const sequelize = require('./db/Sequelize');
const { Propertytables } = require('./db/tables');

class Property extends Model {}
Property.init(Propertytables, { sequelize, modelName: 'property' });

module.exports = Property;
