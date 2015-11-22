
angular.module('vstupApp.ctrl.resultZno', []).
    controller('resultZnoCtrl', function ($scope, localStorageService) {

        $scope.choseZno = localStorageService.get('choseZno') || [];
        updateData();


        $scope.successInput = function (item) {
            if      (item.value > 200) item.value = 200;
            else if (item.value < 100) item.value = 100;

            updateData();
        };

        $scope.addSubject = function () {
            var arr = uniqToArray($scope.zno, $scope.choseZno);

            $scope.choseZno.push({
                name: arr[1].name,
                value: 100,
                active: true
            });

            updateData();
        };

        $scope.diactiveChoseZno = function (item) {
            item.active = !item.active;

            updateData();
        };

        function updateData () {
            if ($scope.s)
                $scope.s.meanBall = summ($scope.choseZno);

            localStorageService.set('choseZno', $scope.choseZno);
        }

    });

