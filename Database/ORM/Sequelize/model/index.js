const User = require('./User');
const Property = require('./Property');
const Reservation = require('./Reservation');

User.hasMany(Property);
User.hasMany(Reservation);
Property.hasMany(Reservation);

User.sync({ force: true });
Property.sync({ force: true });
Reservation.sync({ force: true });

module.exports = { User, Property, Reservation };
