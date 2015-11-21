

angular.module('vstupApp.route', [])

    .config(function ($stateProvider, $urlRouterProvider) {
         $urlRouterProvider.otherwise('/');

         $stateProvider
             .state('search', {
                 url: '/',
                 views: {
                     header: {
                         templateUrl: 'template/header.html'
                     },
                     menu: {
                         templateUrl: 'template/menu.html'
                     },
                     '@': {
                         templateUrl: 'template/search.html'
                     }
                 }
             })

            ;
    });