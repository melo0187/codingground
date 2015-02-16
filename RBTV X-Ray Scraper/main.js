var xray = require('x-ray');

xray('http://rocketbeans.tv/shows/')
  .select([{
    $root: '.show',
    title: '.show-desc .show-text h3',
    description: '.show-desc .show-text',
    thumb: '.show-image img[src]',
    meta: {
      info: '.show-info'
    }
  }])
  .write('out.json');