
angular.module('vstupApp.ctrl.cabinet', []).
    controller('cabinetCtrl', function ($scope) {

        $scope.subjects = [
            {
                name: 'Українська мова',
                value: 150
            }
        ];

        $scope.addSubject = function () {
            $scope.subjects.push({});
        };

        $scope.successInput = function (item) {
            var b;

            if      (item.value > 200) b = 200;
            else if (item.value < 100) b = 100;
            else    return false;

            return item.value = b;
        };

    });

