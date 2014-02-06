/*
 * Copyright (C) 2012-2013 Kito Cheng (kito@0xlab.org)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LIBELFXX_ELF_SECTION_H_
#define _LIBELFXX_ELF_SECTION_H_

#include <elf.h>
#include <stdint.h>
#include <stdio.h>

namespace libelfxx {

class ElfSection {
  public:
    ElfSection(const char *name, Elf32_Shdr *shdr, uint8_t *rawData);
    ElfSection(const char *name, Elf64_Shdr *shdr, uint8_t *rawData);

    const char *getNameStr() const;
    uint32_t getName() const;
    uint64_t getFlags() const;
    uint64_t getAddr() const;
    uint64_t getOffset() const;
    uint64_t getSize() const;
    uint32_t getLink() const;
    uint32_t getInfo() const;
    uint64_t getAddralign() const;
    uint64_t getEntsize() const;

    uint8_t *getContent();

    void print(FILE *fp);
  private:
    const char *_nameStr;
    uint32_t _name;
    uint64_t _flags;
    uint64_t _addr;
    uint64_t _offset;
    uint64_t _size;
    uint32_t _link;
    uint32_t _info;
    uint64_t _addralign;
    uint64_t _entsize;

    uint8_t *_content;
};

};
#endif