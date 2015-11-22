
angular.module('vstupApp.ctrl.goal', []).
    controller('goalCtrl', function ($scope) {


        $scope.setStep = function (name) {
            $scope.step = name;
        };

        $scope.map = [
            {
                name: 'Basic',
                list: []
            },
            {
                name: 'Pascal',
                list: [
                    {
                        name: 'Паскаль - это просто!',
                        course: 'Coursera',
                        success: true
                    },
                    {
                        name: 'Pascal Has Never Been That Ez',
                        course: 'Udemy',
                        success: true
                    },
                    {
                        name: 'Lets learn Pascal',
                        course: 'Prometheus'
                    },
                    {
                        name: 'Pascal Crash Course 101',
                        course: 'edX'
                    }
                ]
            },
            {
                name: 'Алгоритмiзацiя',
                list: []
            },
            {
                name: 'C++',
                list: []
            },
            {
                name: 'Патерни',
                list: []
            }
        ]

    });

