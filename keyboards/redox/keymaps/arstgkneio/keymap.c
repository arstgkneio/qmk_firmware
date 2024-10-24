<<<<<<< HEAD
/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
   _CLMK,
   _EXT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_CLMK] = LAYOUT(
=======
#include QMK_KEYBOARD_H

//Helful defines
#define _colemak 0
#define _rulemak 1 
#define _extlayer 2 
#define N_K_R_O MAGIC_HOST_NKRO

enum unicode_names {
  RU_A, RU_BE, RU_VE, RU_GHE, RU_DE, RU_IE, RU_IO, RU_ZHE, RU_ZE, RU_I, RU_Y, RU_KA, RU_EL, RU_EM, RU_EN, RU_O, RU_PE, RU_ER, RU_ES, RU_TE, RU_U, RU_EF, RU_HA, RU_TSE, RU_CHE, RU_SHA, RU_SHCHA, RU_HSGN, RU_YERU, RU_SSGN, RU_E, RU_YU, RU_YA, RU_a, RU_be, RU_ve, RU_ghe, RU_de, RU_ie, RU_io, RU_zhe, RU_ze, RU_i, RU_y, RU_ka, RU_el, RU_em, RU_en, RU_o, RU_pe, RU_er, RU_es, RU_te, RU_u, RU_ef, RU_ha, RU_tse, RU_che, RU_sha, RU_shcha, RU_hsgn, RU_yeru, RU_ssgn, RU_e, RU_yu, RU_ya,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	 [_colemak] = LAYOUT(
>>>>>>> 02cdebd6fff035ec59d65f213492be05d74d002c
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_ESC  ,                          KC_EQL  ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
<<<<<<< HEAD
     MO(_EXT),KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,LSFT(KC_9),                      LSFT(KC_0),KC_K    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,MO(_EXT),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX, KC_M    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LGUI ,KC_LBRC ,KC_RBRC ,     KC_LALT ,    KC_SPC  ,KC_LCTL ,        KC_RCTL ,KC_ENT ,    KC_QUOT ,     KC_UP   ,KC_LEFT   ,KC_DOWN ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_EXT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,RGB_M_R ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_WH_U ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F11  ,                          KC_F12  ,XXXXXXX ,XXXXXXX ,KC_UP   ,XXXXXXX ,XXXXXXX ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_WH_D ,KC_LSFT ,KC_LCTL ,XXXXXXX ,KC_WBAK ,                          KC_WFWD ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RIGHT ,KC_BSPC ,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RGB_MOD ,RGB_RMOD ,KC_BTN1 ,KC_BTN2,        KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,KC_COMM ,KC_DOT  ,KC_MS_U ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_LALT ,    XXXXXXX ,XXXXXXX ,        KC_BTN1 ,KC_BTN2,     XXXXXXX ,     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
=======
     MO(2)   ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_K    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,MO(2)   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,TO(1)   ,KC_M    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_PSCR ,KC_LGUI ,KC_LBRC ,KC_RBRC ,     KC_LALT ,    KC_SPC  ,KC_LCTL ,        KC_RCTL ,KC_ENT ,    KC_QUOT ,     KC_UP   ,KC_LEFT   ,KC_DOWN ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     ),

     [_rulemak] = LAYOUT(
  //┌──────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┐                                                                     ┌──────────────────┬──────────────────┬──────────────────┬─────────────────┬─────────────────┬──────────────────┐
     XXXXXXX       ,KC_1              ,KC_2              ,KC_3              ,KC_4              ,KC_5              ,                                                                            KC_6        ,      KC_7        ,      KC_8        ,     KC_9        ,     KC_0        ,      KC_MINS     ,
  //├──────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────┐                                       ┌──────────────┼──────────────────┼──────────────────┼──────────────────┼─────────────────┼─────────────────┼──────────────────┤
     KC_TAB        ,XP(RU_ya, RU_YA)  ,XP(RU_zhe, RU_ZHE) ,XP(RU_ef, RU_EF) ,XP(RU_pe, RU_PE)  ,XP(RU_be, RU_BE)  ,KC_ESC        ,                                             KC_EQL   ,XP(RU_y, RU_Y)    ,XP(RU_el, RU_EL)  ,XP(RU_u, RU_U)  ,XP(RU_yeru, RU_YERU) ,XP(RU_yu, RU_YU) ,XP(RU_ssgn, RU_SSGN),
  //├──────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────┤                                       ├──────────────┼──────────────────┼──────────────────┼──────────────────┼─────────────────┼─────────────────┼──────────────────┤
     MO(2)         ,XP(RU_a, RU_A)    ,XP(RU_er, RU_ER)  ,XP(RU_es, RU_ES)  ,XP(RU_te, RU_TE)  ,XP(RU_ghe, RU_GHE) ,XP(RU_sha, RU_SHA)  ,                        XP(RU_shcha, RU_SHCHA) ,XP(RU_ka, RU_KA)  ,XP(RU_en, RU_EN)  ,XP(RU_ie, RU_IE)  ,XP(RU_i, RU_I)   ,XP(RU_o, RU_O)   ,XP(RU_e, RU_E),
  //├──────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────┼──────────────┐         ┌──────────────┼──────────────┼──────────────────┼──────────────────┼──────────────────┼─────────────────┼─────────────────┼──────────────────┤
     KC_LSFT       ,XP(RU_ze, RU_ZE)  ,XP(RU_ha, RU_HA)  ,XP(RU_tse, RU_TSE) ,XP(RU_de, RU_DE) ,XP(RU_ve, RU_VE)  ,XXXXXXX       ,XXXXXXX       ,              XXXXXXX   ,TO(0)         ,XP(RU_em, RU_EM) ,XP(RU_che, RU_CHE) ,XP(RU_io, RU_IO)  ,KC_DOT           ,KC_SLSH          ,KC_RSFT           ,
  //├──────────────┼──────────────────┼──────────────────┼──────────────────┼──────────────┬───┴──────────────┬───┼──────────────┼──────────────┤         ├──────────────┼──────────────┼────┬─────────────┴───┬──────────────┼──────────────────┼─────────────────┼─────────────────┼──────────────────┤
     XXXXXXX       ,XXXXXXX           ,KC_LBRC           ,KC_RBRC                           ,KC_LALT              ,KC_SPC        ,KC_LCTL       ,              KC_RCTL   ,     KC_ENT   ,          KC_QUOT     ,                     KC_LEFT     ,     KC_UP       ,     KC_DOWN     ,         KC_RGHT 
  //└──────────────┴──────────────────┴──────────────────┴──────────────────┘              └──────────────────┘   └──────────────┴──────────────┘         └──────────────┴──────────────┘    └─────────────────┘              └──────────────────┴─────────────────┴─────────────────┴──────────────────┘
     ),

 	 [_extlayer] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SLEP ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,RGB_M_R ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_WAKE ,XXXXXXX ,KC_WH_U ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F11  ,                          KC_F12  ,XXXXXXX ,XXXXXXX ,KC_UP   ,XXXXXXX ,XXXXXXX ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_WH_D ,KC_LSFT ,KC_LCTL ,XXXXXXX ,KC_WBAK ,                          KC_WFWD ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RIGHT ,KC_BSPC ,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     N_K_R_O ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RGB_MOD ,RGB_RMOD ,KC_BTN1 ,KC_BTN2,        KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,KC_COMM ,KC_DOT  ,KC_MS_U ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     RGB_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_LALT ,    XXXXXXX ,XXXXXXX ,        KC_BTN1 ,KC_BTN2,     XXXXXXX ,     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     )
};

const uint32_t PROGMEM unicode_map[] = {
   [RU_A]  = 0x0410, //А
   [RU_BE] = 0x0411, //Б
   [RU_VE] = 0x0412, //В
   [RU_GHE] = 0x0413, //Г
   [RU_DE] = 0x0414, //Д
   [RU_IE] = 0x0415, //Е
   [RU_IO] = 0x0401, //Ё
   [RU_ZHE] = 0x0416, //Ж
   [RU_ZE] = 0x0417, //З
   [RU_I] = 0x0418, //И
   [RU_Y] = 0x0419, //Й
   [RU_KA] = 0x041A, //К
   [RU_EL] = 0x041B, //Л
   [RU_EM] = 0x041C, //М
   [RU_EN] = 0x041D, //Н
   [RU_O] = 0x041E, //О
   [RU_PE] = 0x041F, //П
   [RU_ER] = 0x0420, //Р
   [RU_ES] = 0x0421, //С
   [RU_TE]= 0x0422, //Т
   [RU_U] = 0x0423, //У
   [RU_EF] = 0x0424, //Ф
   [RU_HA] = 0x0425, //Х
   [RU_TSE] = 0x0426, //Ц  
   [RU_CHE] = 0x0427, //Ч
   [RU_SHA] = 0x0428, //Ш
   [RU_SHCHA] = 0x0429, //Щ
   [RU_HSGN] = 0x042A, //Ъ
  [RU_YERU] = 0x042B, //Ы
  [RU_SSGN] = 0x042C, //Ь
  [RU_E] = 0x042D, //Э
  [RU_YU] = 0x042E, //Ю
  [RU_YA] = 0x042F, //Я
  [RU_a] = 0x0430, //а
  [RU_be] = 0x0431, //б
  [RU_ve] = 0x0432, //в
  [RU_ghe] = 0x0433, //г
  [RU_de] = 0x0434, //д
  [RU_ie] = 0x0435, //е
  [RU_io] = 0x0451, //ё
  [RU_zhe] = 0x0436, // ж
  [RU_ze] = 0x0437, //з
  [RU_i] = 0x0438, //и
  [RU_y] = 0x0439, //й 
  [RU_ka] = 0x043A, //к
  [RU_el] = 0x043B, // л
  [RU_em] = 0x043C, //м
  [RU_en] = 0x043D, //н
  [RU_o] = 0x043E, //о
  [RU_pe] = 0x043F, //п
  [RU_er] = 0x0440, //р
  [RU_es] = 0x0441, //с
  [RU_te] = 0x0442, //т
  [RU_u] = 0x0443, //у
  [RU_ef] = 0x0444, //ф
  [RU_ha] = 0x0445, //х
  [RU_tse] = 0x0446, //ц
  [RU_che] = 0x0447, //Ч
  [RU_sha] = 0x0448, //ш
  [RU_shcha] = 0x0449, //щ
  [RU_hsgn] = 0x044A, //ъ
  [RU_yeru] = 0x044B, //ы
  [RU_ssgn] = 0x044C, //ь
  [RU_e] = 0x044D, // э
  [RU_yu] = 0x044E, //ю
  [RU_ya] = 0x044F, //я
};


void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC);
>>>>>>> 02cdebd6fff035ec59d65f213492be05d74d002c
};
