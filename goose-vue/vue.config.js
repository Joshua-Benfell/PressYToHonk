module.exports = {
  publicPath: "./",
  css: {
    //With Sass-loader included this includes the files into all the component styles.
    loaderOptions: {
      sass: {
        data: `@import "@/styles/_variables.scss";` //import variables and mixins
      }
    }
  }
};
