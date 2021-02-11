<template>
  <div class="button yButton" @click="doHonk">
    <img class="yIcon" src="@/assets/img/Y.png" alt="Y" />
  </div>
</template>

<script>
import { mapState, mapGetters } from "vuex";
import { Howl } from "howler";

export default {
  name: "Y",
  data() {
    return {};
  },
  computed: {
    ...mapState({
      instrument: state => state.instrument.instrument,
      currentSound: state => state.instrument.currentCount,
      sound: state => state.sound.soundState,
      deviceID: state => state.webBluetoothState.deviceID,
      serviceUUID: state => state.webBluetoothState.serviceUUID,
      characteristicUUID: state => state.webBluetoothState.characteristicUUID
    }),
    ...mapGetters({
      device: "webBluetooth/device", // Library getter for getting the a device based on the ID
      deviceServices: "webBluetooth/servicesForDevice",
      serviceCharacteristic: "webBluetooth/characteristicsForService"
    }),
    connected() {
      // Method that returns a boolean based on whether we are connected to to a device. This is determined by the device ID and then the object gatt property
      if (this.deviceID !== "") {
        return this.device(this.deviceID).gatt.connected;
      } else {
        return false;
      }
    },
    service() {
      let services = this.deviceServices(this.deviceID);
      for (let service of services) {
        if (service.uuid === this.serviceUUID) {
          return service;
        }
      }
      return null;
    },
    characteristic() {
      let characteristics = this.serviceCharacteristic(this.service);
      for (let characteristic of characteristics) {
        if (characteristic.uuid === this.characteristicUUID) {
          return characteristic;
        }
      }
      return null;
    },
    writeOptions() {
      return {
        characteristic: this.characteristic,
        value: this.valueToWrite
      };
    },
    valueToWrite() {
      let text = this.instrument.id + 1 + "," + (this.currentSound + 1);
      return this.encode(text);
    }
  },
  methods: {
    doHonk() {
      if (this.connected) {
        this.$store.dispatch(
          "webBluetooth/writeCharacteristic",
          this.writeOptions
        );
      }

      if (this.sound) {
        //play honk
        let filePath = require.context("@/assets/sounds", false, /\.wav$/);
        let sound = new Howl({
          src: filePath(
            "./" + this.instrument.name + "_" + this.currentSound + ".wav"
          )
        });
        sound.play();
      }

      this.$store.dispatch("instrument/changeCurrentCount");
    },
    encode(text) {
      let enc = new TextEncoder();
      return enc.encode(text);
    }
  }
};
</script>

<style lang="scss">
.yButton {
  height: 200px;
  width: 200px;
  position: absolute;
  left: 50%;
  top: 50%;
  transform: translate(-50%, -50%);
  .yIcon {
    max-width: 125px;
    max-height: 125px;
  }
}
</style>
