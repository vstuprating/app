
angular.module('vstupApp.ctrl.search', []).
    controller('searchCtrl', function ($scope, $http, $sce) {

        $scope.s = {};

        $scope.startSearch = function () {
            if (!$scope.s.idCity) delete $scope.s.idCity;
            if (!$scope.s.idBranch) delete $scope.s.idBranch;
            if (!$scope.s.idUniversity) delete $scope.s.idUniversity;
            if (!$scope.s.idDirection) delete $scope.s.idDirection;

            console.log($scope.s);

            $http.get('http://web.prolaby.com/api/get/chance', {params: $scope.s})
                .success(function (data) {
                    $scope.chances = data;
                    console.log('chance', data);
                });
        };

        $scope.changeParamsSearch = function () {
            var sUniversity = {
                idCity: $scope.s.idCity,
                idBranch: $scope.s.idBranch
            };

            var sDirections = {
                idCity: $scope.s.idCity,
                idBranch: $scope.s.idBranch,
                idUniversity: $scope.s.idUniversity
            };

            if (!sUniversity.idCity) delete sUniversity.idCity;
            if (!sUniversity.idBranch) delete sUniversity.idBranch;

            if (!sDirections.idCity) delete sDirections.idCity;
            if (!sDirections.idBranch) delete sDirections.idBranch;
            if (!sDirections.idUniversity) delete sDirections.idUniversity;

            console.log(sUniversity);
            if (!_.isEmpty(sUniversity)) {
                $http.get('http://web.prolaby.com/api/get/university', {params: sUniversity})
                    .success(function (data) {
                        $scope.university = data;
                        //console.log('university', data);
                    });
            }
            else {
                $scope.university = _.clone($scope.allUniversity);
            }

            console.log(sDirections);
            if (!_.isEmpty(sDirections)) {
                $http.get('http://web.prolaby.com/api/get/directions', {params: sDirections})
                    .success(function (data) {
                        $scope.directions = data;
                        //console.log('directions', data);
                    });
            }
            else {
                $scope.directions = _.clone($scope.allDirections);
            }
        };


        $scope.getHTML = function (val) {
            return $sce.trustAsHtml(val);
        }

    });

