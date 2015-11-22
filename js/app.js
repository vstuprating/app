
angular.module('vstupApp', [
      'ngTouch'
    , 'ui.router'
    , 'ngDialog'
    , 'LocalStorageModule'
    , 'angular-loading-bar'

    //, 'vstupApp.run'
    //, 'vstupApp.config'
    , 'vstupApp.route'

    , 'vstupApp.directives'
    , 'vstupApp.ctrl.app'
    , 'vstupApp.ctrl.search'
    , 'vstupApp.ctrl.cabinet'
    , 'vstupApp.ctrl.resultZno'
]);

function uniqToArray(a, b) {
    var arr = _.clone(a),
        arrSelect = _.clone(b);

    _.forEach(arr, function(arrItem, i){
        _.forEach(arrSelect, function (item) {
            if (arrItem && arrItem.name === item.name)
                arr[i] = null;
        });
    });
    return _.compact(arr);
}

function summ (arr) {
    var s = 0;
    var i = 0;

    _.forEach(arr, function (item) {
        if (item.active) {
            i++;
            return s += item.value;
        }
    });

    s = s / i;

    return '' + s.toFixed(2);
}