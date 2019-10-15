const { Sequelize } = require('sequelize');
const UserTables = {
  username: {
    type: Sequelize.STRING(255),
    allowNull: false
  },
  password: {
    type: Sequelize.STRING(64),
    allowNull: false
  },
  email: {
    type: Sequelize.STRING(255),
    allowNull: false
  },
  superhost: {
    type: Sequelize.BOOLEAN,
    defaultValue: true
  },
  profileimage: {
    type: Sequelize.STRING(255),
    allowNull: true
  },
  introduction: {
    type: Sequelize.TEXT,
    allowNull: true
  }
};

const Propertytables = {
  propertyname: {
    type: Sequelize.STRING(45),
    allowNull: false
  },
  opendate: {
    type: Sequelize.DATE,
    allowNull: false
  },
  closedate: {
    type: Sequelize.DATE,
    allowNull: false
  },
  minimumcapacity: {
    type: Sequelize.INTEGER,
    allowNull: false
  },
  maximumcapacity: {
    type: Sequelize.INTEGER,
    allowNull: false
  },
  price: {
    type: Sequelize.INTEGER,
    defaultValue: 0
  },
  bedroomnumber: {
    type: Sequelize.INTEGER,
    defaultValue: 0
  },
  bednumber: {
    type: Sequelize.INTEGER,
    defaultValue: 0
  },
  bathroomnumber: {
    type: Sequelize.INTEGER,
    defaultValue: 0
  },
  star: {
    type: Sequelize.INTEGER,
    defaultValue: 0
  },
  reviewnumber: {
    type: Sequelize.INTEGER,
    defaultValue: 0
  }
};

const ReservationTables = {
  checkin: {
    type: Sequelize.DATE,
    allowNull: false
  },
  checkout: {
    type: Sequelize.DATE,
    allowNull: false
  },
  cancelled: {
    type: Sequelize.BOOLEAN,
    defaultValue: false
  },
  personnel: {
    type: Sequelize.INTEGER,
    allowNull: false
  },
  price: {
    type: Sequelize.INTEGER,
    defaultValue: 100000000
  }
};

module.exports = { UserTables, Propertytables, ReservationTables };
