
angular.module('vstupApp.ctrl.search', []).
    controller('searchCtrl', function ($scope, $http) {

        $scope.choseZno = [
            {
                name: 'Українська мова і література',
                value: 100
            }
        ];


        $scope.addSubject = function () {
            //_.filter($scope.subjects, function (item) {
            //    return item.name =
            //});

            $scope.choseZno.push({
                value: 100
            });
        };

        $scope.startSearch = function () {
            console.log($scope.s);

            $http.get('http://web.prolaby.com/api/get/chance', {params: $scope.s})
                .success(function (data) {
                    $scope.chances = data;
                    console.log('chance', data);
                });
        }

    });

