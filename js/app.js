
angular.module('vstupApp', [
      'ngTouch'
    , 'ui.router'
    , 'ngDialog'
    , 'LocalStorageModule'
    //, 'ngAnimate'

    //, 'vstupApp.run'
    //, 'vstupApp.config'
    , 'vstupApp.route'

    , 'vstupApp.directives'
    , 'vstupApp.ctrl.app'
    , 'vstupApp.ctrl.search'
    , 'vstupApp.ctrl.cabinet'
]);
