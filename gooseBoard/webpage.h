#ifndef __WEBPAGE__
#define  __WEBPAGE__

char webpage[] PROGMEM = R"=====(
  <html>
    <head>
      <title>Press Y to Honk</title>
      <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    </head>
    <body>
    <div id="app">
      <div class="button yButton">
        <img src="src/assets/img/Y.png" alt="Y" class="yIcon">
      </div>
      <div class="row mx-0 col-12 col-lg-6 offset-lg-3 instrumentTray">
        <span class="col-4 col-sm-2">
          <div class="button instrumentButton">
            <img src="src/assets/img/honk.png" alt="honk-icon" class="instrumentIcon">
          </div>
        </span>
        <span class="col-4 col-sm-2">
          <div class="button instrumentButton">
            <img src="src/assets/img/glass.png" alt="glass-icon" class="instrumentIcon">
          </div>
        </span>
        <span class="col-4 col-sm-2">
          <div class="button instrumentButton">
            <img src="src/assets/img/harmonica.png" alt="harmonica-icon" class="instrumentIcon">
          </div>
        </span>
        <span class="col-4 col-sm-2">
          <div class="button instrumentButton">
            <img src="src/assets/img/soap.png" alt="soap-icon" class="instrumentIcon">
          </div>
        </span>
        <span class="col-4 col-sm-2">
          <div class="button instrumentButton">
            <img src="src/assets/img/trashlid.png" alt="trashlid-icon" class="instrumentIcon">
          </div>
        </span>
        <span class="col-4 col-sm-2">
          <div class="button instrumentButton">
            img src="src/assets/img/walkie_talkie.png" alt="walkie_talkie-icon" class="instrumentIcon">
          </div>
        </span>
      </div>
    </div>
    </body>
    <script>

    </script>
    <style>
      #app {
          font-family: Helvetica,Arial,sans-serif;
      }

      .button{
        display: flex;
        justify-content: center;
        align-items: center;
        background-color: #bbb;
        border-radius: 50%;
        cursor: pointer;
      }

      .button:hover{
        background-color: #999;
      }

      img{
        -khtml-user-select: none;
        -o-user-select: none;
        -moz-user-select: none;
        -webkit-user-select: none;
        user-select: none;
      }

      .yButton{
        height: 200px;
        width: 200px;
        position: absolute;
        left: 50%;
        top: 50%;
        transform: translate(-50%, -50%);
      }
      .yIcon{
        max-width: 125px;
        max-height: 125px;
      }

      .instrumentButton{
        width: 75px;
        height: 75px;
        margin: 10px auto;
      }

      .instrumentIcon{
        max-width: 50px;
        max-height: 50px;
      }

      .col-4 {
          flex: 0 0 33.33333%;
          max-width: 33.33333%;
      }

      .col-12 {
          flex: 0 0 100%;
          max-width: 100%;
      }

      .row {
          display: flex;
          flex-wrap: wrap;
          margin-right: -15px;
          margin-left: -15px;
      }

      *, :after, :before {
          box-sizing: border-box;
      }

      .col-12,.col-4,.col-sm-2,.col-lg-3{
          position: relative;
          width: 100%;
          padding-right: 15px;
          padding-left: 15px;
      }

      .ml-0, .mx-0 {
          margin-left: 0!important;
      }

      .mr-0, .mx-0 {
          margin-right: 0!important;
      }

      @media (min-width: 576px){
        .col-sm-2 {
          flex: 0 0 16.66667%;
          max-width: 16.66667%;
        }
      }

      @media (min-width: 992px){
        .offset-lg-3 {
          margin-left: 25%!important;
        }
        .col-lg-6 {
          flex: 0 0 50%;
          max-width: 50%;
        }
      }

      .instrumentTray {
        position: fixed;
        bottom: 0;
      }
    </style>
  </html>
)=====";
#endif
