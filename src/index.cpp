//
//  index.cpp
//  Copyright (c) 2014-2019, MyMonero.com
//
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//	conditions and the following disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//	of conditions and the following disclaimer in the documentation and/or other
//	materials provided with the distribution.
//
//  3. Neither the name of the copyright holder nor the names of its contributors may be
//	used to endorse or promote products derived from this software without specific
//	prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
//  THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
//  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//
#include <stdio.h>
#include <emscripten/bind.h>
#include <emscripten.h>
//
#include "serial_bridge_index.hpp"
#include "serial_bridge_utils.hpp"
//
using namespace std;
//
/*
string decode_address(const string &args_string)
{
    try {
        return serial_bridge::decode_address(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string is_subaddress(const string &args_string)
{
    try {
        return serial_bridge::is_subaddress(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string is_integrated_address(const string &args_string)
{
    try {
        return serial_bridge::is_integrated_address(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
//
string estimated_tx_network_fee(const string &args_string)
{
    try {
        return serial_bridge::estimated_tx_network_fee(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
//
string estimate_fee(const string &args_string)
{
    try {
        return serial_bridge::estimate_fee(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
//
string estimate_tx_weight(const string &args_string)
{
    try {
        return serial_bridge::estimate_tx_weight(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
//
string estimate_rct_tx_size(const string &args_string)
{
    try {
        return serial_bridge::estimate_rct_tx_size(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
*/
//
string generate_key_image(const string &args_string)
{
    try {
        return serial_bridge::generate_key_image(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
//
string generate_key_derivation(const string &args_string)
{
    try {
        return serial_bridge::generate_key_derivation(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string derive_public_key(const string &args_string)
{
    try {
        return serial_bridge::derive_public_key(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
/*
string derive_subaddress_public_key(const string &args_string)
{
    try {
        return serial_bridge::derive_subaddress_public_key(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
*/
string derivation_to_scalar(const string &args_string)
{
    try {
        return serial_bridge::derivation_to_scalar(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string decodeRct(const string &args_string)
{
    try {
        return serial_bridge::decodeRct(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string decodeRctSimple(const string &args_string)
{
    try {
        return serial_bridge::decodeRctSimple(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string encrypt_payment_id(const string &args_string)
{
    try {
        return serial_bridge::encrypt_payment_id(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
/*
string send_step1__prepare_params_for_get_decoys(const string &args_string)
{
    try {
        return serial_bridge::send_step1__prepare_params_for_get_decoys(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
*/
string send_step2__try_create_transaction(const string &args_string)
{
    try {
        return serial_bridge::send_step2__try_create_transaction(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string extract_utxos(const string &args_string)
{
    try {
        return serial_bridge::extract_utxos(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string pre_step2_tie_unspent_outs_to_mix_outs_for_all_future_tx_attempts(const string &args_string)
{
    try {
        return serial_bridge::pre_step2_tie_unspent_outs_to_mix_outs_for_all_future_tx_attempts(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
string verify_trezor_key_image(const string &args_string)
{
    try {
        return serial_bridge::verify_trezor_key_image(args_string);
    } catch (std::exception &e) {
        return serial_bridge_utils::error_ret_json_from_message(e.what());
    }
}
//
EMSCRIPTEN_BINDINGS(my_module)
{ // C++ -> JS
    //
    // emscripten::function("decode_address", &decode_address);
    // emscripten::function("is_subaddress", &is_subaddress);
    // emscripten::function("is_integrated_address", &is_integrated_address);
    //
    // emscripten::function("estimated_tx_network_fee", &estimated_tx_network_fee);
    // emscripten::function("estimate_fee", &estimate_fee);
    // emscripten::function("estimate_tx_weight", &estimate_tx_weight);
    // emscripten::function("estimate_rct_tx_size", &estimate_rct_tx_size);
    //
    emscripten::function("generate_key_image", &generate_key_image);
    emscripten::function("generate_key_derivation", &generate_key_derivation);
    emscripten::function("derive_public_key", &derive_public_key);
    // emscripten::function("derive_subaddress_public_key", &derive_subaddress_public_key);
    emscripten::function("decodeRct", &decodeRct);
    emscripten::function("decodeRctSimple", &decodeRctSimple);
    emscripten::function("derivation_to_scalar", &derivation_to_scalar);
    emscripten::function("encrypt_payment_id", &encrypt_payment_id);
    //
    // emscripten::function("send_step1__prepare_params_for_get_decoys", &send_step1__prepare_params_for_get_decoys);
    emscripten::function("pre_step2_tie_unspent_outs_to_mix_outs_for_all_future_tx_attempts", &pre_step2_tie_unspent_outs_to_mix_outs_for_all_future_tx_attempts);
    emscripten::function("send_step2__try_create_transaction", &send_step2__try_create_transaction);
    //
    emscripten::function("extract_utxos", &extract_utxos);
    emscripten::function("verify_trezor_key_image", &verify_trezor_key_image);
}
extern "C"
{ // C -> JS
}
int main() {
  // printf("hello, world!\n");
  return 0;
}
