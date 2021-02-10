<template>
  <div id="app">
    <header class="configButtons row">
      <BTButton />
      <SoundButton />
    </header>

    <main class="mainRow row">
      <Y />
    </main>

    <footer class="instrumentTray row">
      <div class="instrumentWrapper">
        <div
          class="instrumentButtonContainer"
          v-for="instrument in instruments"
          :key="instrument.id"
        >
          <InstrumentButton
            :key="instrument.id"
            :name="instrument.name"
            :icon="instrument.icon"
          />
        </div>
      </div>
    </footer>
  </div>
</template>

<script>
import InstrumentButton from "./components/InstrumentButton";
import Y from "./components/Y";
import SoundButton from "./components/SoundButton";
import BTButton from "./components/BTButton";
import { INSTRUMENTS } from "./constants";

export default {
  name: "app",
  components: {
    InstrumentButton,
    Y,
    SoundButton,
    BTButton
  },
  data() {
    return {};
  },
  mounted() {
    let newInstrument = "honk";
    this.$store.dispatch("instrument/changeInstrument", { newInstrument });
  },
  computed: {
    instruments() {
      return INSTRUMENTS;
    }
  }
};
</script>

<style lang="scss">
#app {
  font-family: Helvetica, Arial, sans-serif;
}
</style>
