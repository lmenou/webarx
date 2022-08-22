#ifndef _PARSING_H_
#define _PARSING_H_

#include <string>
#include <vector>

// Represent all the interesting elements from a Query XML item
class ParsedItem {
private:
  std::string title{};
  std::string abstract{};
  std::string url{};
  std::vector<std::string> authors{};

public:
  std::string getTitle() const { return this->title; }
  std::string getAbstract() const { return this->abstract; }
  std::string getUrl() const { return this->url; }
  std::vector<std::string> getAuthors() const { return this->authors; }

  void setTitle(std::string title) { this->title = title; }
  void setAbstract(std::string abstract) { this->abstract = abstract; }
  void setUrl(std::string url) { this->url = url; }
  void setAuthors(std::vector<std::string> authors) { this->authors = authors; }
};

// Parse the XML documents contains in std::string response and returns a
// std::vector of parsed_items which is the result.
// TODO: Implement my own container, this shall be better
class ParsedDoc {
private:
  std::vector<ParsedItem> parsedItems;

public:
  std::vector<ParsedItem> getItems() const { return this->parsedItems; }
  std::vector<std::string> getTitles() const;
  void parse(std::string xmlresponse);
  void screenRenderer() const;
  friend std::ostream &operator<<(std::ostream &os, const ParsedDoc &parsedDoc);
};

#endif
