var gulp = require('gulp')
    , sass = require('gulp-sass')
    , csso = require('gulp-csso')
    , gutil = require('gulp-util')
    , concat = require('gulp-concat')
    , notify = require('gulp-notify')
    , rename = require("gulp-rename")
    , uglify = require('gulp-uglify')
    , coffee = require('gulp-coffee')
    , useref = require('gulp-useref')
    , svgmin = require('gulp-svgmin')
    , inject = require('gulp-inject')
    , connect = require('gulp-connect')
    , complexity = require('gulp-complexity')
    , ngAnnotate = require('gulp-ng-annotate')
    , minifyHTML = require('gulp-minify-html')
    , bowerFiles = require('main-bower-files')
    , filesToJson = require('gulp-files-to-json')
    , autoprefixer = require('gulp-autoprefixer')
    , imageminJpegtran = require('imagemin-jpegtran')
    , imageminPngquant = require('imagemin-pngquant')
    , angularFilesort = require('gulp-angular-filesort')
    ;


//server
gulp.task('server', function () {
    connect.server({
        livereload: true
    });
});


//html
gulp.task('html', function () {
    gulp.src(['./index.html', './template/*.html'])
        //.pipe(useref.assets())
        //.pipe(useref.assets().restore())
        //.pipe(useref())
        //.pipe(rename({ name: 'index.html' }))
        //.pipe(gulp.dest('./'))
        .pipe(connect.reload());
    //.pipe(notify("Change index.html"));
});


gulp.task('index', function () {
    var js = {
        app: {
            src: './js/**/*.js',
            name: 'app'
        }
    };

    gulp.src('./index.html')
        .pipe(inject(
            gulp.src(
                bowerFiles(),
                {base: './bower_components' },
                {read: false}
            ),
            {name: 'bower', relative: true}
        )
    )
        .pipe(inject(
            gulp.src(js.app.src).pipe(angularFilesort()),
            {name: js.app.name, relative: true}
        )
    )
        .pipe(gulp.dest('./'))
        .pipe(connect.reload());
});


//css
gulp.task('css', function () {
    gulp.src('./css/*.css')
        .pipe(connect.reload());
});


//js
gulp.task('js', function () {
    gulp.src('./js/**/*.js')
        .pipe(connect.reload());
});


//coffee
gulp.task('coffee', function () {
    gulp.src('./js/**/*.coffee')
        .pipe(coffee({bare: true}).on('error', gutil.log))
        .pipe(gulp.dest('./js/'))
        .pipe(connect.reload());
});

//складність і зручність підтримки коду
gulp.task('complexity', function () {
    return gulp.src('./js/**/*.js')
        .pipe(complexity());
});

//архівування проекту
//gulp.task('zip', function () {
//    return gulp.src('./*/**')
//        .pipe(zip('app.zip'))
//        .pipe(gulp.dest('./'));
//});


//minify pic
gulp.task('minify-image', function () {
    gulp.src('./image/*')
        .pipe(imageminJpegtran({progressive: true})())
        .pipe(imageminPngquant({quality: '65-80', speed: 4})())
        .pipe(gulp.dest('./public/'));
});

//minify svg
gulp.task('minify-svg', function () {
    return gulp.src('./images/**/*.svg')
        .pipe(svgmin())
        .pipe(gulp.dest('./out'));
});


gulp.task('sass', function () {
    gulp.src('./sass/**/*.sass')
        .pipe(sass({
            outputStyle: 'expanded',
            sourceComments: 'normal'
        }).on('error', gutil.log))
        .pipe(gulp.dest('./css/'));
});


//concat
gulp.task('concat-js', function () {
    gulp.src([
        './js/owl.carousel.js',
        './js/app.js'
    ])
        .pipe(concat('app.min.js'))
        .pipe(uglify())
        .pipe(gulp.dest('./js/'));
});


gulp.task('svgToJSON', function () {
    gulp.src('./images/icon/control/*.svg')
        .pipe(svgmin())
        .pipe(filesToJson('icons.json'))
        .pipe(gulp.dest('./out'));
});

//watch
gulp.task('watch', function () {
    gulp.watch('./index.html', ['html']);
    gulp.watch('./template/**/*.html', ['html']);
    gulp.watch('./sass/**/*', ['sass']);
    gulp.watch('./css/**/*', ['css']);
    gulp.watch('./js/**/*.js', ['js']);
    gulp.watch('./js/**/*.coffee', ['coffee']);
});


//minify css
gulp.task('minify-css', function () {
    gulp.src('./css/*.css')
        .pipe(autoprefixer({
            browsers: ['last 38 versions'],
            cascade: false
        }))
        //.pipe(csso())
        //.pipe(rename({ extname: '.min.css' }))
        .pipe(gulp.dest('./css/'));
});


//minify js
gulp.task('minify-js', function () {
    gulp.src('./js/*')
        .pipe(ngAnnotate())
        .pipe(uglify())
        .pipe(gulp.dest('./public/js/'))
});


//minify html
gulp.task('minify-html', function () {
    var opts = {
        conditionals: true,
        spare: true
    };

    return gulp.src('./html/*.html')
        .pipe(minifyHTML(opts))
        .pipe(gulp.dest('./dist/'));
});

gulp.task('build-static', ['index', 'sass', 'coffee']);
gulp.task('default', ['server', 'build-static', 'watch']);