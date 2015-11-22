

angular.module('vstupApp.route', [])

    .config(function ($stateProvider, $urlRouterProvider) {
         $urlRouterProvider.otherwise('/search');

         $stateProvider
             .state('page', {
                 url: '/',
                 abstract: true,
                 views: {
                     header: {
                         templateUrl: 'template/header.html'
                     },
                     menu: {
                         templateUrl: 'template/menu.html'
                     }
                 }
             })

                .state('page.search', {
                     url: 'search',
                     views: {
                         '@': {
                             controller: 'searchCtrl',
                             templateUrl: 'template/search.html'
                         }
                     }
                })

                .state('page.cabinet', {
                    url: 'cabinet',
                    views: {
                        '@': {
                            controller: 'cabinetCtrl',
                            templateUrl: 'template/cabinet.html'
                        }
                    }
                })

                .state('page.goal', {
                    url: 'goal',
                    views: {
                        '@': {
                            templateUrl: 'template/goal.html'
                        }
                    }
                })

            ;
    });