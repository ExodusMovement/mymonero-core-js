'use strict'

const MyMoneroCoreBridgeEssentialsClass = require('./monero_utils/MyMoneroCoreBridgeEssentialsClass.js')
const MyMoneroCoreCppWASM = require('./monero_utils/MyMoneroCoreCpp_WASM.js')

async function loadMyMoneroCore(options) {
  const thisModule = await MyMoneroCoreCppWASM(options).ready
  const instance = new MyMoneroCoreBridgeEssentialsClass(thisModule)
  return instance
}

module.exports = { loadMyMoneroCore }
