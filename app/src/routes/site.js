const router = require('express').Router();

const siteController = require('../app/controllers/SiteController')

router.get('/', siteController.index);
router.post('/location', siteController.createLocation);
module.exports = router;