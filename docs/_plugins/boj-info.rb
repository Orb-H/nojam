module Jekyll
    class BojInfoInlineTag < Liquid::Tag
        def initialize(tag_name, input, tokens)
            super
            @input = input.to_i
        end

        def render(context)
            output = ""
            site = context.registers[:site]
            site.collections['docs'].each do |page|
                unless page.data['solve_num'].nil?
                    if page.data['solve_num'] == @input
                        output += "[#{page.data['solve_num']} - #{page.data['solve_name']}](http://noj.am/#{page.data['solve_num']})"
                        break
                    end
                end
            end

            return output
        end
    end
end

Liquid::Template.register_tag("boj_info", Jekyll::BojInfoInlineTag)