<template>
  <div id="app">
    <Y @honk="doHonk()" />
    <div
      class="row mx-0 col-12 col-lg-6 offset-lg-3 instrumentTray"
      id="instrumentTray"
    >
      <span
        class="col-4 col-sm-2"
        v-for="instrument in instruments"
        :key="instrument.name"
      >
        <InstrumentButton
          :key="instrument.name"
          :name="instrument.name"
          :icon="instrument.icon"
          :active="isSelected(instrument.name)"
          @instrumentChange="changeInstrument(instrument.name)"
        />
      </span>
    </div>
  </div>
</template>

<script>
import InstrumentButton from "./components/InstrumentButton";
import Y from "./components/Y";
import { Howl } from "howler";

export default {
  name: "app",
  components: {
    InstrumentButton,
    Y
  },
  data() {
    return {
      instruments: [
        {
          name: "honk",
          icon: "honk.png"
        },
        {
          name: "glass",
          icon: "glass.png"
        },
        {
          name: "harmonica",
          icon: "harmonica.png"
        },
        {
          name: "soap",
          icon: "soap.png"
        },
        {
          name: "trashlid",
          icon: "trashlid.png"
        },
        {
          name: "walkie_talkie",
          icon: "walkie_talkie.png"
        }
      ],
      counts: {
        honk: 5,
        glass: 4,
        harmonica: 6,
        soap: 4,
        trashlid: 5,
        walkie_talkie: 3
      },
      selectedInstrument: "",
      maxHonks: 0,
      honkNum: 0,
      soundEnabled: true
    };
  },
  mounted() {
    this.changeInstrument("honk");
  },
  methods: {
    isSelected(instrument) {
      return instrument == this.selectedInstrument;
    },
    changeInstrument(newInstr) {
      //console.log(newInstr)
      this.selectedInstrument = newInstr;
      this.maxHonks = this.counts[newInstr];
      this.honkNum = 0;
    },
    doHonk() {
      if (!this.soundEnabled) {
        return;
      }
      if (this.honkNum == this.maxHonks) {
        this.honkNum = 0;
      }

      //play honk
      let filePath = require.context("@/assets/sounds", false, /\.wav$/);
      let sound = new Howl({
        src: filePath(
          "./" + this.selectedInstrument + "_" + this.honkNum + ".wav"
        )
      });
      sound.play();

      this.honkNum++;
    }
  }
};
</script>

<style lang="scss">
#app {
  font-family: Helvetica, Arial, sans-serif;
}

.instrumentTray {
  position: fixed !important;
  bottom: 0;
}

@media (min-width: 992px) {
  #instrumentTray {
    margin-left: 25% !important;
  }
}
</style>
