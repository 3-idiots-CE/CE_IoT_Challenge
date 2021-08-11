const Location = require('../models/Location');
const { multipleMongooseToObject } = require('../../util/mongoose')

class SiteController {
    index (req, res, next) {
        Location.find({})
        .then((locations) => {
            res.render('home', {
                locations: multipleMongooseToObject(locations)
            })
        })
    }
    createLocation (req, res, next) {
        const location = new Location(req.body);
        location.save();
        return res.json("msg: successfully");
    }
}

module.exports = new SiteController();