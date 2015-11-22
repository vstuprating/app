
angular.module('vstupApp.ctrl.goal', []).
    controller('goalCtrl', function ($scope, $http) {


        $scope.setStep = function (name) {
            $scope.step = name;
        };

        $scope.setSpec = function (e) {
            if (e.keyCode === 13) {
                e.preventDefault();
                console.time('a')

                $http.get('http://web.prolaby.com/api/get/directions', {params: {idBranch: 41}})
                    .success(function (data) {
                        $scope.v = true;
                        console.timeEnd('a')
                    });
            }
        };

        $scope.map = [
            {
                name: 'HTML',
                list: []
            },
            {
                name: 'CSS',
                list: []
            },
            {
                name: 'JavaScript',
                list: [
                    {
                        name: 'JavaScript Road Trip',
                        course: 'codeschool',
                        success: true
                    },
                    {
                        name: 'jQuery',
                        course: 'codeschool',
                        success: true
                    },
                    {
                        name: 'Angular JS',
                        course: 'codeschool'
                    },
                    {
                        name: 'Reactjs',
                        course: 'hexlet'
                    }
                ]
            },
            {
                name: 'PHP',
                list: []
            },
            {
                name: 'MySQL',
                list: []
            }
        ]

    });

