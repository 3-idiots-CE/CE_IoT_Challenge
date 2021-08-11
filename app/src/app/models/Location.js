const mongoose = require('mongoose');
const Schema = mongoose.Schema;
const ObjectId = Schema.ObjectId;

const Location = new Schema(
  {
    name: { type: String, require: true },
    lat: { type: String },
    long: { type: String },
  },
  {
    timestamps: true,
  },
);

module.exports = mongoose.model('Location', Location);
