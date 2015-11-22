
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

        $http.get('http://web.prolaby.com/api/get/zno')
            .success(function (data) {
                $scope.allZno = data;
                $scope.zno = _.clone($scope.allZno);
                //console.log('zno', data);
            });

        $http.get('http://web.prolaby.com/api/get/city')
            .success(function (data) {
                $scope.allCities = data;
                $scope.cities = _.clone($scope.allCities);
                //console.log('cities', data);
            });

        $http.get('http://web.prolaby.com/api/get/branches')
            .success(function (data) {
                $scope.allBranches = data;
                $scope.branches = _.clone($scope.allBranches);
                //console.log('branches', data);
            });

        $http.get('http://web.prolaby.com/api/get/university')
            .success(function (data) {
                $scope.allUniversity = data;
                $scope.university = _.clone($scope.allUniversity);
                //console.log('university', data);
            });

        $http.get('http://web.prolaby.com/api/get/directions')
            .success(function (data) {
                $scope.allDirections = data;
                $scope.directions = _.clone($scope.allDirections);
                //console.log('directions', data);
            });

    });

