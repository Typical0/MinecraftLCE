#include "Minecraft.World/enchantment/Enchantment.h"
#include "Minecraft.World/enchantment/Enchantments.h"
#include "Minecraft.World/enchantment/categories/FeetArmorCategory.h"
#include "Minecraft.World/enchantment/enchantments/FrostWalkerEnchantment.h"

FrostWalkerEnchantment::FrostWalkerEnchantment(const Rarity* rarity,
                                               arrayWithLength<const EquipmentSlot*> equipmentSlots)
    : Enchantment(rarity, FeetArmorCategory::sFeetArmorCategory, equipmentSlots) {
    this->setDescriptionId(0x933DFA4F);
}

int FrostWalkerEnchantment::getMaxLevel() {
    return 2;
}

int FrostWalkerEnchantment::getMinCost(int a2) {
    return 10 * a2;
}

int FrostWalkerEnchantment::getMaxCost(int a2) {
    return this->getMinCost(a2) + 15;
}

bool FrostWalkerEnchantment::isTreasureOnly() {
    return true;
}

bool FrostWalkerEnchantment::checkCompatibility(const Enchantment* other) {
    return Enchantment::checkCompatibility(other) && Enchantments::DEPTH_STRIDER != other;
}