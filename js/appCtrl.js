
angular.module('vstupApp.ctrl.app', []).
    controller('appCtrl', function ($scope, $http) {

        //$scope.zno = [
        //    {name: 'Українська мова і література'},
        //    {name: 'Історія України'},
        //    {name: 'Математика'},
        //    {name: 'Біологія'},
        //    {name: 'Географія'},
        //    {name: 'Фізика'},
        //    {name: 'Хімія'},
        //    {name: 'Англійська мова'},
        //    {name: 'Іспанська мова'},
        //    {name: 'Німецька мова'},
        //    {name: 'Російська мова'},
        //    {name: 'Французька мова'}
        //];

        $scope.successInput = function (item) {
            var b;

            if      (item.value > 200) b = 200;
            else if (item.value < 100) b = 100;
            else    return false;

            return item.value = b;
        };

        $http.get('http://web.prolaby.com/api/get/zno')
            .success(function (data) {
                $scope.zno = data;
                console.log('zno', data);
            });

        $http.get('http://web.prolaby.com/api/get/city')
            .success(function (data) {
                $scope.cities = data;
                console.log('cities', data);
            });

        $http.get('http://web.prolaby.com/api/get/branches')
            .success(function (data) {
                $scope.branches = data;
                console.log('branches', data);
            });

        $http.get('http://web.prolaby.com/api/get/university')
            .success(function (data) {
                $scope.university = data;
                console.log('university', data);
            });

        $http.get('http://web.prolaby.com/api/get/directions')
            .success(function (data) {
                $scope.directions = data;
                console.log('directions', data);
            });

    });

